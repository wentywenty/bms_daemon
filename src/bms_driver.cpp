/*
 * Copyright (C) 2026 wentywenty
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
 
#include "bms_driver.hpp"

#include "tws_bms_driver.hpp"

std::shared_ptr<BmsDriver> BmsDriver::create_bms(const std::string& bms_type,
                                                  const std::string& socket_path) {
    if (bms_type == "TWS") {
        return std::make_shared<TwsBmsDriver>(socket_path);
    } else {
        throw std::runtime_error("BMS type not supported: " + bms_type);
    }
}
