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
 * - $Id: logreal.cpp 4396 2010-12-09 09:56:06Z jabriffa $
 */

#include "logreal.h"

namespace libbase {

// Input/Output Operations

std::ostream& operator<<(std::ostream& s, const logreal& x)
   {
   using std::ios;

   const double lg = -x.logval / log(10.0);

   const ios::fmtflags flags = s.flags();
   s.setf(ios::fixed, ios::floatfield);
   s << pow(10.0, lg - floor(lg));
   s.setf(ios::showpos);
   s << "e" << int(floor(lg));
   s.flags(flags);

   return s;
   }

} // end namespace
