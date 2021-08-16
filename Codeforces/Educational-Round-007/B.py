# Tags: Implementation
# Difficulty: 1.5
# Priority: 5
# Date: 08-06-2017

hh, mm = map(int, input().split(':'))
a = int( input() ) % ( 60 * 24 )
mm += a
hh += mm // 60
mm %= 60
hh %= 24
print('%0.2d:%0.2d' %(hh, mm))
