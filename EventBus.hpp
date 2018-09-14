//
//  EventBus.hpp
//  EventBus
//
//  Created by coderyi on 2018/9/14.
//  Copyright © 2018年 coderyi. All rights reserved.
//

#ifndef EventBus_hpp
#define EventBus_hpp

#include <vector>
#include <string>
#include <functional>
#include <memory>
#include <unordered_map>
#include <algorithm>

namespace EventBus {
    class   BaseMessage
    {
    public:
        BaseMessage(std::string id);
        virtual ~BaseMessage();
        
        unsigned int    getId() const { return m_id; }
        
    protected:
        unsigned int    m_id;
    };

    template<typename T>
    class   Message : public BaseMessage
    {
    public:
        Message(std::string id, T* data) : BaseMessage(id), m_data(data)
        {}
        virtual ~Message()
        {}
        
        T   *getData() const { return m_data.get(); }
        
    protected:
        std::auto_ptr<T>    m_data;
    };
    
    class   Bus
    {
    public:
        Bus();
        ~Bus();
        
        void    addListener(std::string id, std::function<void(BaseMessage*)> function);
        template<typename U>
        Message<U>    *sendMessage(Message<U> *message)
        {
            auto    range = listeners.equal_range(message->getId());
            for_each(range.first, range.second, [message] (std::unordered_multimap<unsigned int, std::function<void(BaseMessage*)>>::value_type& i)
                     {
                         i.second(message);
                     });
            return message;
        }
        
    protected:
        std::unordered_multimap<unsigned int, std::function<void(BaseMessage*)>>  listeners;
    };

}
#endif /* EventBus_hpp */
