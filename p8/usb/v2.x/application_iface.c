/*-------------------------------------------------------------------------
  application_iface.c - Application interface

             (c) 2006 Pierre Gaufillet <pierre.gaufillet@magic.fr> 

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
-------------------------------------------------------------------------*/

/* $Id: application_iface.c,v 1.3 2006/04/17 20:36:15 gaufille Exp $ */

#include "config.h"
#include "common_types.h"

typedef struct {
    uchar invalid;                   // != 0 when the application is not valid
    void* device_descriptor;
    void** configuration_descriptor; // pointer to an array of pointer to configuration descriptors
    uchar** string_descriptor;       // pointer to an array of pointer to string descriptors
    void (*** ep_init)(void);
    void (*** ep_in)(void);
    void (*** ep_out)(void);
    void (*** ep_setup)(void);
    void (*main) (void);
} ApplicationData;

const ApplicationData __at(APPLICATION_DATA_ADDRESS) application_data = {
    0xFF,           // Application is not valid by default
    NULL,           // no device descriptor
    NULL,           // no configuration descriptor
    NULL,           // no string descriptor
    NULL,           // ep_init
    NULL,           // ep_in
    NULL,           // ep_out
    NULL,           // ep_setup
    NULL            // application main
};
