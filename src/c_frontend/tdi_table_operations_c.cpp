// SPDX-FileCopyrightText: 2023 Intel Corporation
// Copyright (C) 2023 Intel Corporation.
//
// SPDX-License-Identifier: Apache-2.0
#ifdef __cplusplus
extern "C" {
#endif
#include <tdi/common/tdi_defs.h>

#include <tdi/common/c_frontend/tdi_operations.h>

#ifdef __cplusplus
}
#endif
#include <tdi/common/tdi_operations.hpp>

tdi_status_t tdi_operations_set_value(tdi_operations_hdl *operations_hdl,
                                      tdi_operations_field_type_e type,
                                      const uint64_t value) {
  auto operations_field = reinterpret_cast<tdi::TableOperations *>(operations_hdl);
  return operations_field->setValue(type, value);
}

tdi_status_t tdi_operations_get_value(const tdi_operations_hdl *operations_hdl,
                                      tdi_operations_field_type_e type,
                                      uint64_t *value) {
  auto operations_field = reinterpret_cast<const tdi::TableOperations *>(operations_hdl);
  return operations_field->getValue(type, value);
}

