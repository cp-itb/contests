# Contest	: IDEAFUSE 2018 Qualification
# Team		: Arurange Code Party
# Author	: Dewita Sonya
# Problem	: G - Necklaces

n, k, c = input().split(' ')
n = int(n)
k = int(k)
c = int(c)
 
fac = []
fac.append(1)
 
for i in range(1001):
	fac.append((i+1)*fac[i])

par = c
ans = 0
deft = k-1 if k>1 else 1
while deft*par<=n:
	if (k+1)*par<n:
		par += c
		continue
	sisa = n-deft*par
	cnt2 = 0
	while cnt2+cnt2 <= sisa:
		cnt1 = sisa if k>1 else par
		cnt1 -= cnt2+cnt2
		tmp = fac[par]
		tmp //= fac[cnt2]
		tmp //= fac[cnt1]
		if k>1:
			tmp //= fac[par-cnt1-cnt2]
		cnt2 += 1
		ans += tmp
	par += c

# formatting
ans = list(str(ans))
length = 0
while len(ans)<4:
	length += 1;
	ans += '0'
 
if len(ans)>=5 and ans[4]>='5':
	ind = 3
	while ind>=0 and ans[ind]=='9':
		ans[ind]='0'
		ind -= 1
	if ind>=0:
		ans[ind] = chr(ord(ans[ind])+1)
	else:
		ans = ['1'] + ans

print(ans[0]+'.'+ans[1]+ans[2]+ans[3]+' x 10^'+str(len(ans)-1-length))
