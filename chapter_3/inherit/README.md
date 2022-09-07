As described in the book, any padding in the subclass will be remained. That is to prevent coping into an subobject overrides the other.

However, in GCC, it seems that not all paddings are remained.

According to our test, GCC seems to try to use as less as possible. But there are premises:
1. Members in the subobjects are remained in the same memory layout as they are in the correspoinding base class object, except that the paddings may be ignored. This is to guarantee that one can consider the subobject as a base class object when accessing the subobject via a pointer of the base class type.
2. Members of multiple subobjects may not be in the order that they are declared. GCC may adjust the orders of the subobjects. But the subobject are in one piece.
3. Members of the derived class are always arranged after all the subobjects.