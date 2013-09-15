/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef KN2PARSER_H_INCLUDED
#define KN2PARSER_H_INCLUDED

#include "KNParser.h"
#include "KNTypes.h"

namespace libkeynote
{

class KNStyle;

class KN2Parser : public KNParser
{
public:
  KN2Parser(const WPXInputStreamPtr_t &input, KNCollector *collector, const KNDefaults &defaults);
  virtual ~KN2Parser();

private:
  virtual void processXmlNode(const KNXMLReader &reader);
  virtual KNXMLReader::TokenizerFunction_t getTokenizer() const;

  void parseDrawables(const KNXMLReader &reader);
  void parseLayer(const KNXMLReader &reader);
  void parseLayers(const KNXMLReader &reader);
  void parseMasterSlide(const KNXMLReader &reader);
  void parseMasterSlides(const KNXMLReader &reader);
  void parseMetadata(const KNXMLReader &reader);
  void parsePage(const KNXMLReader &reader);
  void parseProxyMasterLayer(const KNXMLReader &reader);
  void parseSize(const KNXMLReader &reader, KNSize &size);
  void parseSlide(const KNXMLReader &reader);
  void parseSlideList(const KNXMLReader &reader);
  void parseStickyNotes(const KNXMLReader &reader);
  void parseStyles(const KNXMLReader &reader, bool anonymous);
  void parseStylesheet(const KNXMLReader &reader);
  void parseTheme(const KNXMLReader &reader);
  void parseThemeList(const KNXMLReader &reader);

  void parseBezier(const KNXMLReader &reader);
  void parseBezierRef(const KNXMLReader &reader);
  void parseConnectionLine(const KNXMLReader &reader);
  void parseGeometry(const KNXMLReader &reader);
  void parseGroup(const KNXMLReader &reader);
  void parseImage(const KNXMLReader &reader);
  void parseLine(const KNXMLReader &reader);
  void parseMedia(const KNXMLReader &reader);
  void parsePath(const KNXMLReader &reader);
  void parseShape(const KNXMLReader &reader);
  void parseStickyNote(const KNXMLReader &reader);
  void parsePlaceholder(const KNXMLReader &reader, bool title = false);

  void parseBezierPath(const KNXMLReader &reader);
  void parseCallout2Path(const KNXMLReader &reader);
  void parseConnectionPath(const KNXMLReader &reader);
  void parsePointPath(const KNXMLReader &reader);
  void parseScalarPath(const KNXMLReader &reader);

  void parseBr(const KNXMLReader &reader);
  void parseLayout(const KNXMLReader &reader, const boost::optional<ID_t> &layoutStyle);
  void parseLink(const KNXMLReader &reader, bool ref = false);
  void parseP(const KNXMLReader &reader);
  void parseSpan(const KNXMLReader &reader);
  void parseTab(const KNXMLReader &reader);
  void parseText(const KNXMLReader &reader);
  void parseTextBody(const KNXMLReader &reader, const boost::optional<ID_t> &layoutStyle);
  void parseTextStorage(const KNXMLReader &reader, const boost::optional<ID_t> &layoutStyle);

private:
  unsigned m_version;
};

}

#endif //  KN2PARSER_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
