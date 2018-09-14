EventBus是一种发布/订阅模式的框架，主要用于解耦。可以看一下[greenrobot](https://github.com/greenrobot/EventBus)的图

<br/>
<img src="https://github.com/greenrobot/EventBus/raw/master/EventBus-Publish-Subscribe.png" width="500" height="187"/>

EventBus的优点是基本没有依赖关系，module间通信只需要知道事件名字就可以，是我个人比较推荐的。

示例

```
#include "EventBus.h"
#include <iostream>

void    foo(EventBus::BaseMessage *i)
{
	EventBus::Message<std::string>  *j = static_cast<EventBus::Message<std::string>*>(i);

	std::cout<<*j->getData() << std::endl;
}

int main()
{
	EventBus::Bus   b;
	b.addListener("hello", foo);
	delete b.sendMessage(new EventBus::Message<std::string>("hello", new std::string("Hello world !")));
	return 0;
}

```
