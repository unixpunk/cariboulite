/* -*- c++ -*- */
/*
 * Copyright 2023 CaribouLabs LTD.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CARIBOULITE_CARIBOULITESOURCE_IMPL_H
#define INCLUDED_CARIBOULITE_CARIBOULITESOURCE_IMPL_H

#include <gnuradio/caribouLite/caribouLiteSource.h>
#include <CaribouLite.hpp>
#include "circular_buffer.h"

namespace gr 
{
    namespace caribouLite 
    {        
        class caribouLiteSource_impl : public caribouLiteSource
        {
        private:
            CaribouLiteRadio::RadioType _channel;
            bool _enable_agc;
            float _rx_gain;
            float _rx_bw;
            float _sample_rate;
            float _frequency;
            size_t _mtu_size;
            
            CaribouLite* _cl;
            CaribouLiteRadio *_radio;
            circular_buffer<gr_complex> *_rx_queue;

        private:
            void receivedSamples(CaribouLiteRadio* radio, const std::complex<float>* samples, CaribouLiteMeta* sync, size_t num_samples);
            
        public:
            caribouLiteSource_impl(int channel, bool enable_agc, float rx_gain, float rx_bw, float sample_rate, float freq);
            ~caribouLiteSource_impl();

            int work(
                int noutput_items,
                gr_vector_const_void_star &input_items,
                gr_vector_void_star &output_items
            );
        };

    } // namespace caribouLite
} // namespace gr

#endif /* INCLUDED_CARIBOULITE_CARIBOULITESOURCE_IMPL_H */
