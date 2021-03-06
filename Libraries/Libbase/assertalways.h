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
 * - $Id: assertalways.h 4396 2010-12-09 09:56:06Z jabriffa $
 */

#ifndef __assert_h
#define __assert_h

/*!
 * \file
 * \brief   Main Configuration.
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 4396 $
 * - $Date: 2010-12-09 09:56:06 +0000 (Thu, 09 Dec 2010) $
 * - $Author: jabriffa $
 */

// system include files

#include <cassert>

// *** Global namespace ***

// An assertion that is implemented even in release builds

#ifdef NDEBUG
#  define assertalways(_Expression) (void)( (!!(_Expression)) || (libbase::reportassertionandfail(#_Expression, __FILE__, __LINE__), 0) )
#else
#  define assertalways(_Expression) assert(_Expression)
#endif

// Fail with error

#define failwith(_String) libbase::reporterrorandfail(_String, __FILE__, __LINE__)

// *** Within library namespace ***

namespace libbase {

// Debugging tools

void reportassertionandfail(const char *expression, const char *file, int line);
void reporterrorandfail(const char *expression, const char *file, int line);

} // end namespace

#endif
