//
//  EventBus.cpp
//  EventBus
//
//  Created by coderyi on 2018/9/14.
//  Copyright © 2018年 coderyi. All rights reserved.
//

#include "EventBus.hpp"

namespace EventBus
{
    BaseMessage::BaseMessage(std::string id)
    {
        std::hash<std::string>  hash;
        
        m_id = hash(id);
    }
    
    BaseMessage::~BaseMessage()
    {}
    
    Bus::Bus()
    {}
    
    Bus::~Bus()
    {}
    
    void    Bus::addListener(std::string id, std::function<void(BaseMessage*)> function)
    {
        std::hash<std::string>  hash;
        listeners.insert(std::pair<unsigned int, std::function<void(BaseMessage*)>>(hash(id), function));
    }
}
