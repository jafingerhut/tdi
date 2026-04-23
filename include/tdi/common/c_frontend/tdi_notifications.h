/*
 * SPDX-FileCopyrightText: 2023 Intel Corporation
 * Copyright (C) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/** @file tdi_notifications.h
 *
 * @brief Contains TDI Table notifications APIs
 */
#ifndef _TDI_NOTIFICATIONS_H
#define _TDI_NOTIFICATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*tdi_notification_callback)(
    const tdi_table_key_hdl *key,
    const tdi_table_data_hdl *data,
    const tdi_notification_param_hdl *params,
    void *cookie);

tdi_status_t tdi_notifications_set_value(
    tdi_notification_param_hdl *notifications_hdl,
    const tdi_id_t field_id,
    const uint64_t value);

tdi_status_t tdi_notifications_set_value_array(
    tdi_notification_param_hdl *notifications_hdl,
    const tdi_id_t field_id,
    const uint64_t *value,
    const uint32_t array_sz);

tdi_status_t tdi_notifications_get_value(
    const tdi_notification_param_hdl *notifications_hdl,
    const tdi_id_t field_id,
    uint64_t *value);

tdi_status_t tdi_notifications_get_value_array_size(
    const tdi_notification_param_hdl *notification_hdl,
    const tdi_id_t field_id,
    uint32_t *array_size);

tdi_status_t tdi_notifications_get_value_array(
    const tdi_notification_param_hdl *notification_hdl,
    const tdi_id_t field_id,
    uint64_t *val);

#ifdef __cplusplus
}
#endif

#endif  // _TDI_NOTIFICATIONS_H
