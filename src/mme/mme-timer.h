/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MME_TIMER_H
#define MME_TIMER_H

#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forward declaration */
typedef enum {
    MME_TIMER_BASE = 0,

    MME_TIMER_S1_DELAYED_SEND,

    /* Paging procedure for EPS services initiated */
    MME_TIMER_T3413,

    /* DETACH REQUEST sent */
    MME_TIMER_T3422,

    /* ATTACH ACCEPT sent
     * TRACKING AREA UPDATE ACCEPT sent with GUTI
     * TRACKING AREA UPDATE ACCEPT sent with TMSI
     * GUTI REALLOCATION COMMAND sent */
    MME_TIMER_T3450,

    /* AUTHENTICATION REQUEST sent
     * SECURITY MODE COMMAND sent */
    MME_TIMER_T3460,

    /* IDENTITY REQUEST sent */
    MME_TIMER_T3470,

    /* ESM INFORMATION REQUEST sent */
    MME_TIMER_T3489,

    MME_TIMER_SGS_CLI_CONN_TO_SRV,

    MAX_NUM_OF_MME_TIMER,

} mme_timer_e;

typedef struct mme_timer_cfg_s {
    int max_count;
    ogs_time_t duration;
} mme_timer_cfg_t;

mme_timer_cfg_t *mme_timer_cfg(mme_timer_e id);

const char *mme_timer_get_name(mme_timer_e id);

void mme_timer_s1_delayed_send(void *data);

void mme_timer_t3413_expire(void *data);
void mme_timer_t3422_expire(void *data);
void mme_timer_t3450_expire(void *data);
void mme_timer_t3460_expire(void *data);
void mme_timer_t3470_expire(void *data);
void mme_timer_t3489_expire(void *data);

void mme_timer_sgs_cli_conn_to_srv(void *data);

#ifdef __cplusplus
}
#endif

#endif /* MME_TIMER_H */
