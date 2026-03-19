#pragma once

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <memory>
#include <string>

class BmsDriver {
   public:
    BmsDriver() {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_st>());
        logger_ = spdlog::get("bms");
        if (!logger_) {
            logger_ = std::make_shared<spdlog::logger>("bms", std::begin(sinks), std::end(sinks));
            spdlog::register_logger(logger_);
        }
    }
    virtual ~BmsDriver() = default;

    static std::shared_ptr<BmsDriver> create_bms(const std::string& bms_type,
                                                  const std::string& socket_path = "/tmp/bms.sock");

    virtual double get_voltage() const = 0;
    virtual double get_current() const = 0;
    virtual double get_temperature() const = 0;
    virtual double get_percentage() const = 0;     // 0.0 ~ 1.0
    virtual double get_charge() const = 0;         // Ah
    virtual double get_capacity() const = 0;       // Ah
    virtual double get_design_capacity() const = 0;
    virtual uint32_t get_protect_status() const = 0;
    virtual uint16_t get_work_state() const = 0;
    virtual double get_max_cell_voltage() const = 0;
    virtual double get_min_cell_voltage() const = 0;
    virtual uint16_t get_soh() const = 0;          // %
    virtual uint32_t get_cycles() const = 0;
    virtual bool is_connected() const = 0;

   protected:
    std::shared_ptr<spdlog::logger> logger_;
};
