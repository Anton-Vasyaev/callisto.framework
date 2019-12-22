#ifndef SHARED_SCOPE_HANDLER_HPP
#define SHARED_SCOPE_HANDLER_HPP

// std
#include <utility>
#include <mutex>
// project
#include "default_disposer.hpp"


namespace callisto::framework
{
    template<
        typename Type,
        typename DisposerType=DefaultDisposer<Type>
    >
    class SharedHandler
    {
    private:
        using data_type = Type;
        
        using disposer_type = DisposerType;

        Type data;
        DisposerType disposer;


        size_t* ref_counter = nullptr;
        std::mutex* mutex = nullptr;

        bool has_handler = false;


        #pragma region PrivateMethods

        inline void destroy()
        {
            if (!(this->has_handler)) return;

            size_t current_counter = 0;
            {
                std::unique_lock<std::mutex> locker(*(this->mutex));
                (*(this->ref_counter))--;
                if ((*(this->ref_counter)) == 0)
                {
                    disposer(this->data);
                }

                current_counter = *(this->ref_counter);
            }
            if (current_counter == 0)
            {
                if (this->mutex != nullptr)
                {
                    delete this->mutex;
                    this->mutex = nullptr;
                }
                if (this->ref_counter != nullptr)
                {
                    delete this->ref_counter;
                    this->ref_counter = nullptr;
                }
            }
            this->has_handler = false;
        }

        inline void copy_from(
            SharedHandler& other_handler
        )
        {
            this->destroy();

            std::unique_lock(*(other_handler.mutex));

            this->data = other_handler.data;
            this->ref_counter = other_handler.ref_counter;
            this->mutex = other_handler.mutex;
            this->has_handler = other_handler.has_handler;

            (*(this->ref_counter))++;
        }

        inline void move_from(
            SharedHandler&& other_handler
        )
        {
            this->destroy();

            this->data = other_handler.data;
            this->ref_counter = other_handler.ref_counter;
            this->mutex = other_handler.mutex;
            this->has_handler = other_handler.has_handler;

            other_handler.ref_counter = nullptr;
            other_handler.mutex = nullptr;
            other_handler.has_handler = false;
        }

        inline void create_new(
            Type data
        )
        {
            this->destroy();

            try
            {
                this->ref_counter = new size_t;
                this->mutex = new std::mutex();

                this->data = data;
            }
            catch (...)
            {
                if (this->ref_counter != nullptr) delete this->ref_counter;
                if (this->mutex != nullptr) delete this->mutex;

                throw;
            }

            (*(this->ref_counter)) = 1;
            this->data = data;
            this->has_handler = true;
        }

        #pragma endregion

    public:

        #pragma region ConstructAndDestruct

        SharedHandler() { };

        SharedHandler(
            Type data
        )
        {
            this->create_new(data);
        }

        SharedHandler(
            SharedHandler& other_handler
        )
        {
            this->copy_from(other_handler);
        }

        SharedHandler(
            SharedHandler&& other_handler
        )
        {
            this->move_from(other_handler);
        }

        ~SharedHandler()
        {
            this->destroy();
        }

        #pragma endregion


        #pragma region Methods

        void reset(Type data)
        {
            this->create_new(data);
        }

        #pragma endregion

        #pragma region OperatorsOverloading

        SharedHandler& operator=(SharedHandler& other_handler)
        {
            this->copy_from(other_handler);

            return *this;
        }

        SharedHandler& operator=(SharedHandler&& other_handler)
        {
            this->move_from(std::move(other_handler));

            return *this;
        }

        #pragma endregion


        #pragma region GettersAndSetters

        Type& get_data()
        {
            return this->data;
        }

        const Type& getconst_data() const
        {
            return this->data;
        }

        size_t count() const
        {
            return *(this->ref_counter);
        }

        bool has_handler_status() const
        {
            return this->has_handler;
        }

        #pragma endregion
    };
}

#endif