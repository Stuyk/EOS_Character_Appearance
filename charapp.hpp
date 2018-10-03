#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>
#include <string>
#include <tuple>
#include <algorithm>

namespace stuykappearance {
    using namespace eosio;
    using std::string;

    class appearance : public contract {
        using contract::contract;

        public:
            appearance(account_name _self ):contract( _self ), _characters(_self, _self){}

            // Creates an account.
            [[eosio::action]]
            void create( account_name account, string memo );

            // Updates an account based on the option provided and value.
            [[eosio::action]]
            void update( account_name account, string option, uint64_t value, string memo);

            // Empties the table of all accounts.
            [[eosio::action]]
            void cleartable( string memo );

            // Our table to hold all the information. Think of it as a Dictionary / List with the owner being the key.
            struct [[eosio::table]] characterapp {
                account_name owner;
                uint64_t hair;
                uint64_t face;
                uint64_t eyes;
                uint64_t ears;
                uint64_t shirt;
                uint64_t pants;
                uint64_t shoes;

                uint64_t primary_key() const { return owner; }
                EOSLIB_SERIALIZE(characterapp, (owner)(hair)(face)(eyes)(ears)(shirt)(pants)(shoes));
            };
            typedef multi_index<N(characterapp), characterapp> charIndex;

        private:
            // Strings to pair with our table
            const string hair = "hair";
            const string face = "face";
            const string eyes = "eyes";
            const string ears = "ears";
            const string shirt = "shirt";
            const string pants = "pants";
            const string shoes = "shoes";

            // Easier way to call our index.
            charIndex _characters;
    };

    EOSIO_ABI(appearance, (create)(cleartable)(update))
};