#include "character-appearance.hpp"

namespace stuykappearance {
     // Clears the entire table and all accounts.
    void appearance::cleartable( string memo ) {
        require_auth( _self );

        auto itr = _characters.begin();
        while (itr != _characters.end()) {
            itr = _characters.erase(itr);
        }
    }

    void appearance::update( account_name account, string option, uint64_t value, string memo ) {
        require_auth( account );
        require_recipient( account );

        // Find our account and make sure it exists.
        auto iterator = _characters.find( account );
        eosio_assert(iterator != _characters.end(), "Account does not exist.");

        // Modifies the table that exists for the player and adjusts their values.
        // x is our reference to the table and we can assign properties through it.
        _characters.modify( iterator, account, [&](auto& x) {
            if (option == hair)
                x.hair = value;
            if (option == face)
                x.face = value;
            if (option == eyes)
                x.eyes = value;
            if (option == ears)
                x.ears = value;
            if (option == shirt)
                x.shirt = value;
            if (option == pants)
                x.pants = value;
            if (option == shoes)
                x.shoes = value;
        });
    }

    void appearance::create( account_name account, string memo ) {
        require_auth( account );
        require_recipient( account );

        // Create an iterator to try and find the account.
        auto iterator = _characters.find( account );

        // If the account does not exist we will create it.
        // The iterator created above is trying to find the first instance of the account we want to make.
        // If it is found we'll ensure the code exits here.
        eosio_assert(iterator == _characters.end(), "Found existing account. Cannot continue.");

        // Create the account based on the user's account name.
        _characters.emplace( account, [&](auto& x) {
            x.owner = account;
        });
    }
}