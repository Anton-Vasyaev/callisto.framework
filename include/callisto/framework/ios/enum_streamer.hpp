#pragma once

// std
#include <iostream>

namespace callisto::framework
{
    template<typename type>
    class enum_streamer
    {
    private:
        const type& _sequential;

        enum_streamer() = delete;

    public:
        enum_streamer(const type& sequential)
            : _sequential(sequential)
        {
            
        }

        template<typename type2> 
        friend std::ostream& operator<<(
            std::ostream& os, 
            const enum_streamer<type2>& dt
        );
        
    };

    template <typename type> enum_streamer(type) -> enum_streamer<type>;

    template<typename type>
    std::ostream& operator<<(
        std::ostream& os, 
        const enum_streamer<type>& ssp
    )
    {
        os << "[";
        bool first = true;
        for(auto& element : ssp._sequential)
        {
            if(!first) os << " ";
            os << element;

            if(first) first = false;
        }
        os << "]";

        return os;
    }

}
