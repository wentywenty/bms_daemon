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
 
#pragma once

#include <atomic>
#include <shared_mutex>
#include <string>
#include <thread>

#include "bms_driver.hpp"

class TwsBmsDriver : public BmsDriver {
   public:
    explicit TwsBmsDriver(const std::string& socket_path);
    ~TwsBmsDriver() override;

    double get_voltage() const override;
    double get_current() const override;
    double get_temperature() const override;
    double get_percentage() const override;
    double get_charge() const override;
    double get_capacity() const override;
    double get_design_capacity() const override;
    uint32_t get_protect_status() const override;
    uint16_t get_work_state() const override;
    double get_max_cell_voltage() const override;
    double get_min_cell_voltage() const override;
    uint16_t get_soh() const override;
    uint32_t get_cycles() const override;
    bool is_connected() const override;

   private:
    void reader_loop();
    bool try_connect();
    void disconnect();

    std::string socket_path_;
    int sock_fd_ = -1;
    std::atomic<bool> running_{false};
    std::atomic<bool> connected_{false};
    std::thread reader_thread_;
    mutable std::shared_mutex data_mutex_;
    bms::BatteryStatus cached_{};
};
