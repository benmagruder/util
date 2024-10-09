#ifndef UTIL_SERIALIZE_H
#define UTIL_SERIALIZE_H

/*
* Util Package - C++ Utilities for Scientific Computation
*
* Copyright 2010 - 2017, The Regents of the University of Minnesota
* Distributed under the terms of the GNU General Public License.
*/

#include <util/global.h>

namespace Util
{

   /**
   * Serialize one instance of class T.
   *
   * Default implementation calls serialize method of data object.
   * Can be overridden by any explicit specialization.
   *
   * \ingroup Serialize_Module
   *
   * \param ar      archive object
   * \param data    object to be serialized
   * \param version archive version id
   */
   template <class Archive, typename T>
   inline void serialize(Archive& ar, T& data, const unsigned int version)
   {  data.serialize(ar, version); }

   /**
   * Serialize a fixed size array with elements of type T.
   *
   * \ingroup Serialize_Module
   *
   * \param ar  archive object
   * \param data  fixed size array to be serialized
   * \param N  number of elements in fixed-size array
   * \param version archive version id
   */
   template <class Archive, typename T, size_t N>
   inline void serialize(Archive& ar, T data[N], const unsigned int version)
   {  
      for (int i = 0; i < N; ++i) {
         serialize(ar, data[i], version); 
      }
   }

   /**
   * Serialize an enumeration value.
   *
   * \ingroup Serialize_Module
   *
   * \param ar      archive object
   * \param data    object to be serialized
   * \param version archive version id
   */
   template <class Archive, typename T>
   inline void serializeEnum(Archive& ar, T& data, const unsigned int version = 0)
   {  
      unsigned int i;
      if (Archive::is_saving()) {
         i = (unsigned int)data;
      }
      ar & i;
      if (Archive::is_loading()) {
         data = (T)i;
      }
   }

   /**
   * Save a value, or save and check correctness on loading.
   *
   * \ingroup Serialize_Module
   *
   * \param ar      archive object
   * \param data    object to be serialized
   * \param label   label C-string for object.
   */
   template <class Archive, typename T>
   inline void serializeCheck(Archive& ar, T& data, const char* label = "")
   {
      T temp;
      if (Archive::is_saving()) {
         temp = data;
      }
      ar & temp;
      if (Archive::is_loading()) {
         if (temp != data) {
            UTIL_THROW("Inconsistent data");
         }
      }
   }

}
#endif
