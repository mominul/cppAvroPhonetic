# cppAvroPhonetic
[![Build Status](https://travis-ci.org/mominul/cppAvroPhonetic.svg?branch=master)](https://github.com/mominul/cppAvroPhonetic)

A C++ implementation of Avro Phonetic

### Overview
**cppAvroPhonetic** implements the popular Bengali writing solution Avro Phonetic. cppAvroPhonetic has a header only class named **avrophonetic.hpp**. It is actually extracted from the parser written for **scim-avro** by Rifat Nabi.

### Features

* **100%** compatible with **Avro Phonetic** implementation of **Avro Keyboard**.
* **100%** compatible with Unicode specification version 8.0
* Written in **C++11** and compatible with **newer** versions.
* It is a **header only** implementation. So it can be integrated **easily**.

### Dependency

**cppAvroPhonetic** or **avrophonetic.hpp** depends on **STL** and **C++11** specification. So you will need a C++11 compliant compiler to compile. C++11 is supported by these compilers:
* GCC
* Clang
* Microsoft Visual C++

Do not forget to set the necessary switches to enable C++11 (e.g., `-std=c++11` for GCC and Clang).

### Example

Working with cppAvroPhonetic is very easy. Here is an example:

```cpp
#include <iostream>
#include <string>
#include "avrophonetic.hpp"

int main()
{
  // 'AvroPhonetic' is the converter class.
  AvroPhonetic avro;
  std::string bangla;
  bangla = avro.Convert("ami banglay gan gai"); // Outputs "আমি বাংলায় গান গাই"
  std::cout << bangla << std::endl;
  return 0;
}
```

### Acknowledgements

 - **Mehdi Hasan Khan** for originally developing and maintaining **Avro Phonetic**.
 - **Rifat Nabi** for his [scim-avro](https://code.google.com/p/scim-avro/)

### License
<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">


Copyright (C) 2014-2015 Muhammad Mominul Huque <<nahidbinbaten1995@gmail.com>>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

The full license text can be found in `LICENSE`.
