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
 * - $Id: berrou.h 4396 2010-12-09 09:56:06Z jabriffa $
 */

#ifndef __berrou_h
#define __berrou_h

#include "config.h"
#include "interleaver/lut_interleaver.h"
#include "serializer.h"
#include "itfunc.h"

namespace libcomm {

/*!
 * \brief   Berrou's Original Interleaver.
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 4396 $
 * - $Date: 2010-12-09 09:56:06 +0000 (Thu, 09 Dec 2010) $
 * - $Author: jabriffa $
 */

template <class real>
class berrou : public lut_interleaver<real> {
   int M;
protected:
   void init(const int M);
   berrou()
      {
      }
public:
   berrou(const int M)
      {
      init(M);
      }
   ~berrou()
      {
      }

   // Description
   std::string description() const;

   // Serialization Support
DECLARE_SERIALIZER(berrou)
};

} // end namespace

#endif

