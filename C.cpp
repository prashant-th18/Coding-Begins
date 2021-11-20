ll ans = 0, coor = 0;
 11     ll s = 1, e = 1000;
 12     auto f = [&]() -> bool
 13     {
 14         string s; cin >> s;
 15         if(s == "YES") return true;
 16         else return false;
 17     };
 18     while(s <= e)
 19     {
 20         ll mid = (s + e) / 2;
 21         cout << "? " << mid << ' ' << 0 << endl;
 22         if(f())
 23         {
 24             ans = mid;
 25             s = mid + 1;
 26         }
 27         else
 28         {
 29             e = mid - 1;
 30         }
 31     }
 32     ans *= 2LL;
 33     output += (ans * ans);
 34     s = 1, e = 1000;
 35     while(s <= e)
 36     {
 37         ll mid = (s + e) / 2;
 38         cout << "? " << mid << ' ' << ans << endl;
 39         string s; cin >> s;
 40         if(s == "YES") { coor = mid; s = mid + 1; }
 41         else e = mid - 1;