#ifndef CALLISTO_FRAMEWORK_UNIQUE_SCOPE_HANDLER_HPP
#define CALLISTO_FRAMEWORK_UNIQUE_SCOPE_HANDLER_HPP

// std
#include <utility>

namespace callisto::framework
{
    template<typename Type>
    struct DefaultDisposer
    {
        void operator()(Type data);
    };


    template<typename Type, typename DisposerType=DefaultDisposer<Type>>
    class UniqueScopeHandler
    {
    private:
        using data_type = Type;
        using disposed_type = DisposerType;

        bool has_data = false;
        Type data;
        DisposerType disposer;

        #pragma region PrivateMethods

        inline void destroy()
        {
            if(this->has_data)
            {
                this->disposer(this->data);
                this->has_data = false;
            }
        }

        inline void move_from_other(
            UniqueScopeHandler&& other_handler
        )
        {
            this->destroy();
            this->disposer = other_handler.disposer;
            this->data = other_handler.data;
            this->has_data = other_handler.has_data;
            other_handler.has_data = false;
        }

        #pragma endregion

    public:
        #pragma region ConstructAndDestruct

        UniqueScopeHandler() { }

        ~UniqueScopeHandler()
        {
            this->destroy();
        }

        UniqueScopeHandler(
            Type data
        ) 
        { 
            this->data = data;
            this->has_data = true;
        }

        UniqueScopeHandler(
            const UniqueScopeHandler&
        ) = delete;

        UniqueScopeHandler(
            UniqueScopeHandler&& other_handler
        )
        {
            this->move_from_other(std::move(other_handler));
        }

        #pragma endregion


        #pragma region Methods

        void dispose() { this->destroy(); }

        void reset(Type data)
        {
            this->destroy();
            this->data = data;
            this->hasData = true;
        }

        Type release()
        {
            auto release_data = this->data;
            this->has_data = false;
            return release_data;
        }

        #pragma endregion

        #pragma region Operators

        void operator=(UniqueScopeHandler&) = delete;

        void operator=(
            UniqueScopeHandler&& other_handler
        )
        {
            this->move_from_other(std::move(other_handler));
        }

        #pragma endregion
    };
}


#endif