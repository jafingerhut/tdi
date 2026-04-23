// SPDX-FileCopyrightText: 2023 Intel Corporation
// Copyright (C) 2023 Intel Corporation.
//
// SPDX-License-Identifier: Apache-2.0
/** @file tdi_table_notifications.hpp
 *
 *  @brief Contains TDI Table Notifications APIs
 */
#ifndef _TDI_NOTIFICATIONS_HPP
#define _TDI_NOTIFICATIONS_HPP

#include <functional>
#include <memory>
#include <unordered_map>
#include <map>
#include <vector>

#include <tdi/common/tdi_defs.h>
#include <tdi/common/tdi_table_key.hpp>
#include <tdi/common/tdi_table_data.hpp>

namespace tdi {

class Table;

/**
 * @brief Contains input paramaters for notification register
 */
class NotificationParams {
 public:
  virtual ~NotificationParams() = default;

  NotificationParams(const Table *table, tdi_id_t notification_id)
      : table_(table), notification_id_(notification_id){};

  virtual tdi_status_t setValue(const tdi_id_t & /*field_id*/,
                                const uint64_t & /*value*/) {
    return TDI_NOT_SUPPORTED;
  }

  virtual tdi_status_t setValue(const tdi_id_t & /*field_id*/,
                                const std::vector<uint64_t> & /*value*/) {
    return TDI_NOT_SUPPORTED;
  }

  virtual tdi_status_t getValue(const tdi_id_t & /*field_id*/,
                                uint64_t * /*value*/) const {
    return TDI_NOT_SUPPORTED;
  }

  virtual tdi_status_t getValue(const tdi_id_t & /*field_id*/,
                                std::vector<uint64_t> * /*value*/) const {
    return TDI_NOT_SUPPORTED;
  }

  const tdi_id_t &notificationIdGet() const { return notification_id_; };
  const Table *table_;

 private:
  tdi_id_t notification_id_{0};
};

/**
 * @brief TDI Notification cpp callback function
 */
typedef std::function<void(std::unique_ptr<tdi::TableKey> key,
                           std::unique_ptr<tdi::TableData> data,
                           std::unique_ptr<tdi::NotificationParams> params,
                           void *cookie)>
    tdiNotificationCallback;
}  // namespace tdi

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief TDI Notification c callback function
 */
typedef void (*tdi_notification_callback)(
    const tdi_table_key_hdl *key,
    const tdi_table_data_hdl *data,
    const tdi_notification_param_hdl *params,
    void *cookie);
#ifdef __cplusplus
}
#endif

#endif  // _TDI_NOTIFICATIONS_HPP
