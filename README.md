# bit_to_text

## Description

Use this program to represent some characters set from the memory of an old computer (ex. Commodore 64).  

## Usage

```shell
./bittext ../Downloads/characters.901225-01.bin

0c80 03200 255 ff ********
0c81 03201 255 ff ********
0c82 03202 131 83 *.....**
0c83 03203 153 99 *..**..*
0c84 03204 153 99 *..**..*
0c85 03205 131 83 *.....**
0c86 03206 159 9f *..*****
0c87 03207 159 9f *..*****

0c88 03208 255 ff ********
0c89 03209 255 ff ********
0c8a 03210 193 c1 **.....*
0c8b 03211 153 99 *..**..*
0c8c 03212 153 99 *..**..*
0c8d 03213 193 c1 **.....*
0c8e 03214 249 f9 *****..*
0c8f 03215 249 f9 *****..*

...
255, 255, 131, 153, 153, 131, 159, 159, 
255, 255, 193, 153, 153, 193, 249, 249, 
...

```

The first part represents the binary file in text by bit.  
The second part represents the binary file in text to be used at the array initialization.

## Example

```shell
./bittext ../Downloads/characters.901225-01.bin > ../results.txt
```
