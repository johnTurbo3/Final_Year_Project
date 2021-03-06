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
 * - $Id: channel.cpp 4396 2010-12-09 09:56:06Z jabriffa $
 */

#include "channel.h"

namespace libcomm {

// constructors / destructors

channel<sigspace>::channel()
   {
   Eb = 1;
   set_parameter(0);
   }

// setting and getting overall channel SNR

void channel<sigspace>::compute_noise()
   {
   No = 0.5 * pow(10.0, -snr_db / 10.0);
   // call derived class handle
   compute_parameters(Eb, No);
   }

void channel<sigspace>::set_eb(const double Eb)
   {
   channel::Eb = Eb;
   compute_noise();
   }

void channel<sigspace>::set_no(const double No)
   {
   snr_db = -10.0 * log10(2 * No);
   compute_noise();
   }

void channel<sigspace>::set_parameter(const double snr_db)
   {
   channel::snr_db = snr_db;
   compute_noise();
   }

} // end namespace
