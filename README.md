# Htaccess Checker

:warning: For educational purposes only

## Dependencies

- C++11
- cmake >= 2.8

## Building

```
mkdir build
cd build
cmake ..
make
```

## Running

After building the executable, you can run the account checker with:
```
./htac http://mywebsite.com my-combo-list.txt
```

Combo list files have to be in the following format:
```
username1:password1
username2:password2
username3:password3
```
