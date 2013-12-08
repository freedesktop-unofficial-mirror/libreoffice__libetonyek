/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <string.h>

#include <librevenge/librevenge.h>
#include <librevenge-generators/librevenge-generators.h>
#include <librevenge-stream/librevenge-stream.h>

#include <libetonyek/libetonyek.h>

#include "KEYDirectoryStream.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef VERSION
#define VERSION "UNKNOWN VERSION"
#endif

namespace
{

int printUsage()
{
  printf("Usage: pages2text [OPTION] <Pages Document> | <Pages Directory>\n");
  printf("\n");
  printf("Options:\n");
  printf("--info                Display document metadata instead of the text\n");
  printf("--help                Shows this help message\n");
  printf("--version             Output pages2text version\n");
  return -1;
}

int printVersion()
{
  printf("pages2text %s\n", VERSION);
  return 0;
}

} // anonymous namespace

using libetonyek::PAGESDocument;

int main(int argc, char *argv[])
{
  if (argc < 2)
    return printUsage();

  char *szInputFile = 0;
  bool isInfo = false;

  for (int i = 1; i < argc; i++)
  {
    if (!strcmp(argv[i], "--info"))
      isInfo = true;
    else if (!strcmp(argv[i], "--version"))
      return printVersion();
    else if (!szInputFile && strncmp(argv[i], "--", 2))
      szInputFile = argv[i];
    else
      return printUsage();
  }

  if (!szInputFile)
    return printUsage();

  using boost::shared_ptr;
  namespace fs = boost::filesystem;

  fs::path path(szInputFile);
  shared_ptr<librevenge::RVNGInputStream> input;
  if (is_directory(path))
    input.reset(new conv::KEYDirectoryStream(path));
  else
    input.reset(new librevenge::RVNGFileStream(szInputFile));

  libetonyek::PAGESDocumentType type = libetonyek::PAGES_DOCUMENT_TYPE_UNKNOWN;
  if (!libetonyek::PAGESDocument::isSupported(input.get(), &type))
  {
    fprintf(stderr, "ERROR: Unsupported file format!\n");
    return 1;
  }

  if (libetonyek::PAGES_DOCUMENT_TYPE_MAIN_FILE == type)
  {
    path.remove_filename();
    input.reset(new conv::KEYDirectoryStream(path));
  }

  librevenge::RVNGString output;
  librevenge::RVNGTextTextGenerator documentGenerator(output, isInfo);

  if (!PAGESDocument::parse(input.get(), &documentGenerator))
  {
    fprintf(stderr, "ERROR: Parsing failed!\n");
    return 1;
  }

  if (output.empty())
  {
    fprintf(stderr, "ERROR: No output was produced!\n");
    return 1;
  }

  printf("%s", output.cstr());

  return 0;
}

/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */