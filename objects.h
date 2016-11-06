/*

Simple VOIP objects.

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


// $Revision: 4920 $ $Date:: 2016-11-06 #$ $Author: serge $

#ifndef SIMPLE_VOIP_OBJECTS_H
#define SIMPLE_VOIP_OBJECTS_H

#include <string>                   // std::string
#include <cstdint>                  // uint32_t

namespace simple_voip
{

// ******************* GENERICS *******************

struct IObject
{
    virtual ~IObject() {};
};

struct ForwardObject: public IObject
{
};

struct CallbackObject: public IObject
{
};

struct RequestObject: public ForwardObject
{
    uint32_t        job_id;
};

struct ResponseObject: public CallbackObject
{
    uint32_t        job_id;
};

// ******************* REGISTRATION EVENTS *******************

struct Registered: public CallbackObject
{
};

struct Unregistered: public CallbackObject
{
    std::string     descr;
};

// ******************* ERRORS *******************

struct ErrorResponse: public ResponseObject
{
    uint32_t        errorcode;
    std::string     descr;
};

struct RejectResponse: public ResponseObject
{
    uint32_t        errorcode;
    std::string     descr;
};

// ******************* CALL *******************

struct InitiateCallRequest: public RequestObject
{
    std::string     party;
};

struct InitiateCallResponse: public ResponseObject
{
    uint32_t        call_id;
};

struct DropRequest: public RequestObject
{
    uint32_t        call_id;
};

struct DropResponse: public ResponseObject
{
};

// ******************* IN-CALL REQUESTS *******************

struct PlayFileRequest: public RequestObject
{
    uint32_t        call_id;
    std::string     filename;
    bool            play_in_loop;
};

struct PlayFileResponse: public ResponseObject
{
};

struct PlayFileStopRequest: public RequestObject
{
    uint32_t        call_id;
};

struct PlayFileStopResponse: public ResponseObject
{
};

struct RecordFileRequest: public RequestObject
{
    uint32_t        call_id;
    std::string     filename;
};

struct RecordFileResponse: public ResponseObject
{
};

struct RecordFileStopRequest: public RequestObject
{
    uint32_t        call_id;
};

struct RecordFileStopResponse: public ResponseObject
{
};

// ******************* "BEFORE CONNECTION" EVENTS *******************

struct Failed: public CallbackObject
{
    enum type_e
    {
        FAILED,
        REFUSED,
        BUSY,
        NOANSWER
    };

    uint32_t        call_id;
    type_e          type;
    std::string     descr;
};

struct Dialing: public CallbackObject
{
    uint32_t        call_id;
};

struct Ringing: public CallbackObject
{
    uint32_t        call_id;
};

struct Connected: public CallbackObject
{
    uint32_t        call_id;
};

// ******************* "AFTER CONNECTION" EVENTS *******************

struct ConnectionLost: public CallbackObject
{
    uint32_t        call_id;
    std::string     descr;
};

struct CallDuration: public CallbackObject
{
    uint32_t        call_id;
    uint32_t        t;
};

struct DtmfTone: public CallbackObject
{
    enum tone_e
    {
        TONE_0  = 0,
        TONE_1,
        TONE_2,
        TONE_3,
        TONE_4,
        TONE_5,
        TONE_6,
        TONE_7,
        TONE_8,
        TONE_9,
        TONE_A,
        TONE_B,
        TONE_C,
        TONE_D,
        TONE_STAR,
        TONE_HASH,
    };

    uint32_t        call_id;
    tone_e          tone;
};

} // namespace simple_voip

#endif  // SIMPLE_VOIP_OBJECTS_H
