/*

Dummy.

Copyright (C) 2016 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 4858 $ $Date:: 2016-10-19 #$ $Author: serge $

#ifndef DUMMY_H
#define DUMMY_H

#include "i_simple_voip.h"          // ISimpleVoip

namespace dummy {

class Dummy: virtual public simple_voip::ISimpleVoip
{
public:
    Dummy();
    ~Dummy();

    virtual bool init(
            const simple_voip::Config           & config,
            simple_voip::ISimpleVoipCallback    * callback,
            std::string                         & error_msg );

    virtual void consume( const simple_voip::ForwardObject * req );

    virtual void shutdown();
};

} // namespace dummy

#endif  // DUMMY_H
