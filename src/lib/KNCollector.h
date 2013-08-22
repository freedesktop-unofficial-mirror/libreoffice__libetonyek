/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef KNCOLLECTOR_H_INCLUDED
#define KNCOLLECTOR_H_INCLUDED

#include <string>

#include "KNPath_fwd.h"
#include "KNStyle_fwd.h"
#include "KNTypes_fwd.h"

namespace libwpg
{

class WPGPaintInterface;

} // namespace libwpg

namespace libkeynote
{

struct KNSize;

class KNCollector
{
public:
  virtual ~KNCollector() = 0;

  // collector functions

  virtual void collectCharacterStyle(const ID_t &id, const KNStylePtr_t &style) = 0;
  virtual void collectGraphicStyle(const ID_t &id, const KNStylePtr_t &style) = 0;
  virtual void collectHeadlineStyle(const ID_t &id, const KNStylePtr_t &style) = 0;
  virtual void collectLayoutStyle(const ID_t &id, const KNStylePtr_t &style) = 0;
  virtual void collectParagraphStyle(const ID_t &id, const KNStylePtr_t &style) = 0;

  virtual void collectGeometry(const ID_t &id, const KNGeometryPtr_t &geometry) = 0;
  virtual void collectGroup(const ID_t &id, const KNGroupPtr_t &group) = 0;
  virtual void collectImage(const ID_t &id, const KNImagePtr_t &image) = 0;
  virtual void collectLine(const ID_t &id, const KNLinePtr_t &line) = 0;
  virtual void collectMedia(const ID_t &id, const KNMediaPtr_t &media) = 0;
  virtual void collectPath(const ID_t &id, const KNPathPtr_t &path) = 0;

  virtual void collectSize(const KNSize &size) = 0;

  virtual void collectLayer(const ID_t &id, bool ref) = 0;
  virtual void collectPage(const ID_t &id) = 0;

  virtual void collectText(const std::string &text, const ID_t &style) = 0;
  virtual void collectTab() = 0;
  virtual void collectLineBreak() = 0;

  virtual void startPage() = 0;
  virtual void endPage() = 0;
  virtual void startLayer() = 0;
  virtual void endLayer() = 0;
  virtual void startGroup() = 0;
  virtual void endGroup() = 0;

  virtual void startParagraph(const ID_t &style) = 0;
  virtual void endParagraph() = 0;
  virtual void startTextLayout(const ID_t &style) = 0;
  virtual void endTextLayout() = 0;

  // helper functions

  virtual void startSlides() = 0;
  virtual void endSlides() = 0;
  virtual void startThemes() = 0;
  virtual void endThemes() = 0;
};

} // namespace libkeynote

#endif // KNCOLLECTOR_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
