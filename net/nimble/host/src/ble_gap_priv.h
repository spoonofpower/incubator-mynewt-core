/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef H_BLE_GAP_CONN_
#define H_BLE_GAP_CONN_

#include <inttypes.h>
#include "stats/stats.h"
#include "host/ble_gap.h"
struct hci_le_conn_upd_complete;
struct hci_le_conn_param_req;
struct hci_le_conn_complete;
struct hci_disconn_complete;
struct ble_hci_ack;
struct ble_hs_adv;

STATS_SECT_START(ble_gap_stats)
    STATS_SECT_ENTRY(wl_set)
    STATS_SECT_ENTRY(wl_set_fail)
    STATS_SECT_ENTRY(adv_stop)
    STATS_SECT_ENTRY(adv_stop_fail)
    STATS_SECT_ENTRY(adv_start)
    STATS_SECT_ENTRY(adv_start_fail)
    STATS_SECT_ENTRY(adv_set_fields)
    STATS_SECT_ENTRY(adv_set_fields_fail)
    STATS_SECT_ENTRY(adv_rsp_set_fields)
    STATS_SECT_ENTRY(adv_rsp_set_fields_fail)
    STATS_SECT_ENTRY(discover)
    STATS_SECT_ENTRY(discover_fail)
    STATS_SECT_ENTRY(initiate)
    STATS_SECT_ENTRY(initiate_fail)
    STATS_SECT_ENTRY(terminate)
    STATS_SECT_ENTRY(terminate_fail)
    STATS_SECT_ENTRY(cancel)
    STATS_SECT_ENTRY(cancel_fail)
    STATS_SECT_ENTRY(update)
    STATS_SECT_ENTRY(update_fail)
    STATS_SECT_ENTRY(connect_mst)
    STATS_SECT_ENTRY(connect_slv)
    STATS_SECT_ENTRY(disconnect)
    STATS_SECT_ENTRY(rx_disconnect)
    STATS_SECT_ENTRY(rx_update_complete)
    STATS_SECT_ENTRY(rx_adv_report)
    STATS_SECT_ENTRY(rx_conn_complete)
STATS_SECT_END

extern STATS_SECT_DECL(ble_gap_stats) ble_gap_stats;

#define BLE_GAP_CONN_MODE_MAX               3
#define BLE_GAP_DISC_MODE_MAX               3

int ble_gap_locked_by_cur_task(void);
void ble_gap_rx_adv_report(struct ble_hs_adv *adv);
int ble_gap_rx_conn_complete(struct hci_le_conn_complete *evt);
void ble_gap_rx_disconn_complete(struct hci_disconn_complete *evt);
void ble_gap_rx_update_complete(struct hci_le_conn_upd_complete *evt);
void ble_gap_rx_param_req(struct hci_le_conn_param_req *evt);
int ble_gap_rx_l2cap_update_req(uint16_t conn_handle,
                                struct ble_gap_upd_params *params);
int ble_gap_master_in_progress(void);
int ble_gap_slave_in_progress(void);
int ble_gap_update_in_progress(uint16_t conn_handle);
int ble_gap_wl_busy(void);

int ble_gap_init(void);

#endif
