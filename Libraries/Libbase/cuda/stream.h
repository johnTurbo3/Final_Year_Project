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
 * - $Id: stream.h 5613 2011-06-29 16:57:30Z jabriffa $
 */

#ifndef __cuda_stream_h
#define __cuda_stream_h

#include "config.h"
#include "cuda-all.h"

namespace cuda {

// Determine debug level:
// 1 - Normal debug output only
// NOTE: since this is a header, it may be included in other classes as well;
//       to avoid problems, the debug level is reset at the end of this file.
#ifndef NDEBUG
#  undef DEBUG
#  define DEBUG 1
#endif

#ifdef __CUDACC__

/*!
 * \brief   A CUDA stream
 * \author  Johann Briffa
 *
 * \section svn Version Control
 * - $Revision: 5613 $
 * - $Date: 2011-06-29 17:57:30 +0100 (Wed, 29 Jun 2011) $
 * - $Author: jabriffa $
 *
 * This class represents an identifier for a sequence of commands that
 * executes in order.
 *
 * Note that this is a host-only object. Device code has no interface to other
 * streams.
 */

class stream {
protected:
   /*! \name Object representation */
   cudaStream_t sid; //!< Stream identifier
   // @}

private:
   /*! \name Law of the Big Three */
   /*! \brief Copy constructor
    * \note Copy construction is disabled as it has no meaning.
    */
   stream(const stream& x);
   /*! \brief Copy assignment operator
    * \note Copy assignment is disabled as it has no meaning.
    */
   stream& operator=(const stream& x);
   // @}

public:
   /*! \name Constructors */
   /*! \brief Default constructor
    * Creates and initializes stream object.
    */
   stream()
      {
      cudaSafeCall(cudaStreamCreate(&sid));
      }
   // @}

   /*! \name Law of the Big Three */
   /*! \brief Destructor
    * Waits for all tasks in this stream to finish, then destroys the stream
    * object.
    */
   //!
   ~stream()
      {
      cudaSafeCall(cudaStreamDestroy(sid));
      }
   // @}

   /*! \name User interface */
   //! Returns stream identifier to use in kernel calls
   const cudaStream_t& get_id() const
      {
      return sid;
      }
   //! Waits for all tasks in this stream to finish
   void sync() const
      {
      cudaSafeCall(cudaStreamSynchronize(sid));
      }
   // @}
};

#endif

// Reset debug level, to avoid affecting other files
#ifndef NDEBUG
#  undef DEBUG
#  define DEBUG
#endif

} // end namespace

#endif
