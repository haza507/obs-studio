/******************************************************************************
    Copyright (C) 2016

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <util/darray.h>

struct netif_saddr_item {
	char *name;
	char *addr;
};

struct netif_saddr_data {
	DARRAY(struct netif_saddr_item) addrs;
};

static inline void netif_saddr_data_free(struct netif_saddr_data *data)
{
	for (size_t i = 0; i < data->addrs.num; i++) {
		bfree(data->addrs.array[i].name);
		bfree(data->addrs.array[i].addr);
	}
	da_free(data->addrs);
}

extern bool netif_str_to_addr(struct sockaddr_storage *out, int *addr_len,
		const char *addr);
extern void netif_get_addrs(struct netif_saddr_data *ifaddrs);
extern void netif_log_saddrs(struct netif_saddr_data *sd);
