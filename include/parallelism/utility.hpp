#pragma once

#include <stdint.h>

#include <thread>
#include <functional>

namespace mio
{
    namespace parallelism
    {
        namespace wait
        {
            typedef std::function<void(size_t)> handler_t;

            inline auto active = [](size_t) {};
            inline auto yield = [](size_t) { std::this_thread::yield(); };
        } // namespace wait

        constexpr size_t CACHE_LINE = 64;

        template <typename T, size_t SIZE>
        struct alignas(SIZE) alignas_t
        {
            T value;

            operator T()
            {
                return value;
            }
        };
    } // namespace parallelism
} // namespace mio