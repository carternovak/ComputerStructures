phase 1
I seeked to main
set a breakpoint at sym.phase_1
continued to breakpoint and inputted arbitrary input
Visualed the code at the breakpoint
I could see the line of text in the Vpp so I just copied it to answers.txt and ran ./bomb answers.txt

phase 2
I seeked to main
set a breakpoint at sym.phase_2
continued to breakpoint and inputted arbitrary input
VppED the code at the breakpoint
I could see that the first number it compared to was 2, so that was the first number
Then i noticed on the line with leal -1(%rax, %rax) which doubles my number and subtracts 1 from it and copies it to %eax
Realizing this I went 2, 3(4-1), 5(6-1), 9(10-1), 17(18-1), 33(34-1) for the passcode

phase 3
I seeked to main
set a breakpoint
continued to breakpoint and inputted arbitrary input
VppED the code at the breakpoint
Saw that the function for string length was returned to eax and is compared with the value 10, meaning the string must be 10 characters long
I noticed the xorl function plays a crucial role in the end result
And that rsp was getting modified with 10 characters, that would soon be used in the comparison between edx and ecx
If this comparison failed it would make a modification that would cause the loop to eventually exit
By taking the first 10 hex values of ecx and xoring them with the 10 characters I found earlier, gives my a string of 10 different characters that defuses the bomb

phase 4
I seeked to main
set a breakpoint
continued to breakpoint and inputted arbitrary input
VppED the code at the breakpoint
One of the starting lines I noticed %d %d which i assumed meant the proper input was 2 integers
The first clue was that it was 7 or below, because the comparison would cause a jump if successful that would lead to the bomb
I noticed the comparison to 5 with my input as well so I guessed 5 as the first number
When I kept running through the debugger the last requirement was to find a number equivalent to %eax
And after running through the code after 5 was right, there was a continuous add and subtract to eax
Eventually this lead to -852 for eax because it subtracted 0x354 from eax, which was made 0 before the series of operations
Plugging in these two number defused the bomb
