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
 * - $Id: rectangular.h 4396 2010-12-09 09:56:06Z jabriffa $
 */

#ifndef __rectangular_h
#define __rectangular_h

#include "config.h"
#include "interleaver/lut_interleaver.h"
#include "serializer.h"

namespace libcomm {

/*!
 * \brief   Rectangular Interleaver.
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 4396 $
 * - $Date: 2010-12-09 09:56:06 +0000 (Thu, 09 Dec 2010) $
 * - $Author: jabriffa $
 *
 */

template <class real>
class rectangular : public lut_interleaver<real> {
   int rows, cols;
protected:
   void init(const int tau, const int rows, const int cols);
   rectangular()
      {
      }
public:
   rectangular(const int tau, const int rows, const int cols)
      {
      init(tau, rows, cols);
      }
   ~rectangular()
      {
      }

   // Description
   std::string description() const;

   // Serialization Support
DECLARE_SERIALIZER(rectangular)
};

} // end namespace

#endif
