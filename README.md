# EOS_Character_Appearance
EOS Smart Contract for generic character appearance.

#### Using the contract
(Anything in 'camelCasing' is a variable)

ie. accountName = YOUR ACCOUNT NAME

#### Get the table for this contract:
```
cleos get table accountName accountName characterapp
```

#### Setup an account for this contract:
Action:
* create
Properties:
* account
* memo
```
cleos push action accountName create '["accountName", "Created Account"]' -p accountName
```

#### Modify an account for this contract:
Action:
* update
Properties:
* account
* option
* value
* memo
Options:
* hair
* face
* eyes
* ears
* shirt
* pants
* shoes
```
cleos push action accountName update '["targetAccount", "hair", 1, "Updated Hair"]' -p targetAccount
```

### Clear the table completely:
Action:
* cleartable
Properties:
* memo
```
cleos push action accountName cleartable '["Cleared the table."]' -p accountName
```

