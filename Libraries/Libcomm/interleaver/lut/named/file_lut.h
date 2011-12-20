/*!
 * \file
 * 
 * Copyright (c) 2010 Johann A. Briffa
 * 
 * This file is part of SimCommSys.
 *
 * SimCommSys is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SimCommSys is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SimCommSys.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * \section svn Version Control
 * - $Id: file_lut.h 4396 2010-12-09 09:56:06Z jabriffa $
 */

#ifndef __file_lut_h
#define __file_lut_h

#include "config.h"
#include "interleaver/lut/named_lut.h"

namespace libcomm {

/*!
 * \brief   File-loaded LUT Interleaver.
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 4396 $
 * - $Date: 2010-12-09 09:56:06 +0000 (Thu, 09 Dec 2010) $
 * - $Author: jabriffa $
 *
 */

template <class real>
class file_lut : public named_lut<real> {
public:
   file_lut(const char *filename, const int tau, const int m);
   ~file_lut()
      {
      }
};

} // end namespace

#endif

