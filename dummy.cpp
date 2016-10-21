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

// $Revision: 4865 $ $Date:: 2016-10-19 #$ $Author: serge $

#include "dummy.h"                      // self

#include "objects.h"                 // InitiateCallResponse

namespace dummy {

Dummy::Dummy()
{
}

Dummy::~Dummy()
{
}

bool Dummy::init(
        const simple_voip::Config           & config,
        simple_voip::ISimpleVoipCallback    * callback,
        std::string                         & error_msg )
{
    error_msg   = "dummy";

    return true;
}

void Dummy::consume( const simple_voip::ForwardObject * req )
{
    delete req;
}

void Dummy::shutdown()
{
}

} // namespace dummy
