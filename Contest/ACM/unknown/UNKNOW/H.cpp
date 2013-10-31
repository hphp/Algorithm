#include <stdio.h>
#include <string.h>
#include <math.h>
long long pow(int ct)
{
	long long res;
		if(ct==0)
				return 1;
					else
						{
								res=pow(ct/2)%200907;
										if(ct%2==0)
												{
															return (res*res)%200907;
																	}
																			else
																					{
																								return (2*res*res)%200907;
																										}
																											}
																											}
																											int main()
																											{
																												long long n;
																													while (scanf ("%lld",&n))
																														{
																																if(n==0)
																																			break;
																																					long long res=1;
																																							if (n==1)
																																										printf ("1\n");
																																												else
																																														{
																																																	if(n%2==0)
																																																				{
																																																								res=(long long)(((pow(n+1)-2)%200907)*1.0/3);
																																																											}
																																																														else
																																																																	{
																																																																					res=(long long)(((pow(n+1)-1)%200907)*1.0/3);
																																																																								}
																																																																											printf ("%lld\n",res);
																																																																													}
																																																																														}
																																																																														} 

