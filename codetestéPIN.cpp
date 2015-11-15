


/////////////////////////////
//PIN
/*
			if ((int)buffer[i] < 0)
			{
				buffer[i] = abs(buffer[i]);
				for(vector<int>::iterator it=int_toswap.begin(); it!=int_toswap.end(); ++it)
				{
					int salut = (*it);
					//cout << hex << (int)(*(unsigned char*)(&(*it))); 
					//SwapEnd(salut);
					//cout << (char)(salut);
				}
				//bitset<8>(
				int_toswap.clear();
				//cout << "\n";
				int_toswap.push_back((int)buffer[i]);
			}
			else
				int_toswap.push_back((int)buffer[i]);
			
			//char* tableau[8] = bitset<8>(buffer[i]);
			//__bswap_32 (uint32_t bitset<8>(buffer[i]));
			//cout << bitset<16>(buffer[i]) << endl;
			//int myInt = ((int)buffer[3+i]<<0) | ((int)buffer[2+i]<<8) | ((int)buffer[1+i]<<16) | (buffer[0+i]<<24);
			//cout << myInt;
			//int int_buffer = (int)(*(unsigned char*)(&buffer[i]));
			
			
			/*int yo = (int)buffer[i];
			unsigned char bytes[4];
			bytes[0] = ((int)buffer[i] >> 24) & 0xFF;
			bytes[1] = ((int)buffer[i] >> 16) & 0xFF;
			bytes[2] = ((int)buffer[i] >>  8) & 0xFF;
			bytes[3] =  (int)buffer[i]        & 0xFF;
			
			buffer[i] = ByteSwap((int)buffer[i]);
			cout << (int)buffer[i];*/
