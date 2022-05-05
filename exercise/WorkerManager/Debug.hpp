//
//  Debug.hpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#ifndef Debug_hpp
#define Debug_hpp

#include <stdio.h>

#ifndef DBG
#define DBG(fmt, args...) do { \
                 fprintf(stdout, "[%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);     \
             } while(0)
#endif
            
#endif /* Debug_hpp */
