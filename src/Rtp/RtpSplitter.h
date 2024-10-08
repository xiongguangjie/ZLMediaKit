﻿/*
 * Copyright (c) 2016-present The ZLMediaKit project authors. All Rights Reserved.
 *
 * This file is part of ZLMediaKit(https://github.com/ZLMediaKit/ZLMediaKit).
 *
 * Use of this source code is governed by MIT-like license that can be found in the
 * LICENSE file in the root of the source tree. All contributing project authors
 * may be found in the AUTHORS file in the root of the source tree.
 */

#ifndef ZLMEDIAKIT_RTPSPLITTER_H
#define ZLMEDIAKIT_RTPSPLITTER_H

#if defined(ENABLE_RTPPROXY)
#include "Http/HttpRequestSplitter.h"

namespace mediakit{

class RtpSplitter : public HttpRequestSplitter{
protected:
    /**
     * 收到rtp包回调
     * @param data RTP包数据指针
     * @param len RTP包数据长度
     * RTP packet received callback
     * @param data RTP packet data pointer
     * @param len RTP packet data length
     
     
     * [AUTO-TRANSLATED:18a85278]
     */
    virtual void onRtpPacket(const char *data, size_t len) = 0;

protected:
    ssize_t onRecvHeader(const char *data, size_t len) override;
    const char *onSearchPacketTail(const char *data, size_t len) override;
    const char *onSearchPacketTail_l(const char *data, size_t len);

private:
    bool _is_ehome = false;
    int _check_ehome_count = 3;
    bool _is_rtsp_interleaved = true;
    size_t _offset = 0;
};

}//namespace mediakit
#endif//defined(ENABLE_RTPPROXY)
#endif //ZLMEDIAKIT_RTPSPLITTER_H
