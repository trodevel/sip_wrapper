/*

Simple VOIP interface.

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

// $Revision: 5024 $ $Date:: 2016-11-17 #$ $Author: serge $

#ifndef SIMPLE_VOIP_I_SIMPLE_VOIP_H
#define SIMPLE_VOIP_I_SIMPLE_VOIP_H

#include <string>                   // std::string
#include <cstdint>                  // uint32_t

namespace simple_voip
{

struct Config
{
    std::string     called_id;
    std::string     username;
    std::string     password;
    std::string     host;
    uint32_t        port;
    uint32_t        relogin_pause; // pause in seconds before the next login attempt
    std::string     agent_name;
};

class ForwardObject;
class CallbackObject;

class ISimpleVoipCallback
{
public:
    virtual ~ISimpleVoipCallback() {};

    virtual void consume( const CallbackObject * req )    = 0;
};

class ISimpleVoip
{
public:
    virtual ~ISimpleVoip() {};

    virtual bool init(
            const Config        & config,
            ISimpleVoipCallback * callback,
            std::string         & error_msg )           = 0;

    virtual void shutdown()                             = 0;

    virtual void consume( const ForwardObject * req )   = 0;
};

} // namespace simple_voip

#endif  // SIMPLE_VOIP_I_SIMPLE_VOIP_H
