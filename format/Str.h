#ifndef UTIL_STR_H
#define UTIL_STR_H

/*
* Util Package - C++ Utilities for Scientific Computation
*
* Copyright 2010 - 2017, The Regents of the University of Minnesota
* Distributed under the terms of the GNU General Public License.
*/

#include <iostream>

namespace Util
{

   /**
   * Wrapper for a std::string, for formatted ostream output.
   *
   * An Str object has std::string value, and an integer output field
   * width. The << operator for an Str object uses the specified width.
   * The value and width may both be specified as parameters to a 
   * constructor. If the width is not specified as a constructor
   * parameter, it is set within the constructor to a default value
   * given by Format::defaultWidth().
   *
   * An Str object may be passed to an ostream as a temporary object.
   * For example, the expression:
   * \code
   *    std::cout << Str("Hello") << Str("World", 20) << std::endl;
   * \endcode
   * outputs "Hello" using the default width, followed by "World" in
   * a field of width 20.
   *
   * \ingroup Format_Module
   */
   class Str
   {

   public:

      /// \name Constructors
      //@{ 
     
      /** 
      * Default constructor.
      */
      Str();

      /**
      * Constructor, set value only.
      *
      * \param value  value of the string
      */
      explicit Str(std::string value);

      /**
      * Constructor, set value and width.
      * 
      * \param value  value of the string
      * \param width  default width (minimum number of characters) 
      */
      Str(std::string value, int width);

      //@}
      ///\name Mutators
      //@{

      /**
      * Set the string value.
      *
      * \param value  value of the string
      */      
      void setValue(std::string value);

      /**
      * Set the default width.
      *
      * \param width  default width (minimum number of characters) 
      */      
      void setWidth(int width);

      //@}
      ///\name Accessors
      //@{
     
      /// Return string value. 
      std::string value() const;

      /// Return default string width.
      int width() const;

      //@}
      
   private:

      std::string value_;
      int width_;

   //friends:

      friend std::istream& operator>>(std::istream& in, Str &object);
      friend std::ostream& operator<<(std::ostream& out, const Str &object);

   };

   /**
   * Input stream extractor for an Str object.
   *
   * \param in  input stream
   * \param object  Str object to be read from stream
   * \return modified input stream
   */
   std::istream& operator>>(std::istream& in, Str &object);

   /**
   * Output stream inserter for an Str object.
   *
   * \param  out  output stream
   * \param  object   Str to be written to stream
   * \return modified output stream
   */
   std::ostream& operator<<(std::ostream& out, const Str &object);

} 
#endif
