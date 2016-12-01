def percent_twentyfy(st, n):
  idx = len(st) - 1 # The end of the string
  jdx = n-1 # The "true" end of the string
  while idx >= 0 and jdx >= 0:
    if st[jdx] == ord(' '):
      st[idx] = '0'
      st[idx-1] = '2'
      st[idx-2] = '%'
      idx -= 3
    else:
      st[idx] = st[jdx]
      idx -= 1
    jdx -= 1

st = bytearray('Mr John Smith    ')
print st
percent_twentyfy(st, 13)
print st
