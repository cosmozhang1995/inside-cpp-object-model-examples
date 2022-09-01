As described in the book, any padding in the subclass will be remained. That is to prevent coping into an subobject overrides the other.

However, in GCC, it seems that not all paddings are remained. For example, in `test.cpp`, we have a class `C` inheriting `A` and `B`. Each class has a `int` member (4 bytes).