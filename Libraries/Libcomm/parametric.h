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
 * - $Id: parametric.h 4396 2010-12-09 09:56:06Z jabriffa $
 */

#ifndef __parametric_h
#define __parametric_h

#include "config.h"

namespace libcomm {

/*!
 * \brief   Parametric Class Interface.
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 4396 $
 * - $Date: 2010-12-09 09:56:06 +0000 (Thu, 09 Dec 2010) $
 * - $Author: jabriffa $
 *
 * Defines a class that takes a scalar parameter.
 */

class parametric {
public:
   /*! \name Constructors / Destructors */
   virtual ~parametric()
      {
      }
   // @}

   /*! \name Parameter handling */
   //! Set the characteristic parameter
   virtual void set_parameter(const double x) = 0;
   //! Get the characteristic parameter
   virtual double get_parameter() const = 0;
   // @}

};

} // end namespace

#endif
