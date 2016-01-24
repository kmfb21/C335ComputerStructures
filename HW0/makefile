##########################################################
# makefile
#
# compile all files needed
#
#   Author: Bo Fang (bofang)
#   Date Created: 01/23/2016
#   Last Modified by: Bo Fang (bofang)
#   Date Last Modified: 01/23/2016
#   Assignment: HW0
#   Part of: CSCI-C335 submissions
#

object= rpn

$(object): $(object).o
	@echo compiling executable file...
	@gcc -o $(object) $(object).o
	@echo and remove .o file...
	@rm $(object).o
$(object).o: $(object).c
	@echo compiling .o file...
	@gcc -c $(object).c

clean:
	@rm *.o
