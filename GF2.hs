import Data.List
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
 
prime :: [Integer]
prime = 2:3:filter isPrime [2*k+1 | k<-[2..]]
 
isPrime :: Integer -> Bool
isPrime n = all ((/=0). mod n  ).takeWhile ( <= ( truncate.sqrt.fromIntegral $ n) ) $ prime
 
pfactor :: Integer -> [ Integer ] -> [Integer]
pfactor n p@( x : xs )
   | n <= 1 = []
   | x ^ 2  > n = [ n ]
   | mod n x == 0 = x : pfactor ( div n x ) p
   | otherwise = pfactor n xs 
 
mobius :: Integer -> Integer
mobius 1 = 1
mobius n
    | facs == ( nub facs ) = ( -1 ) ^ len
    | otherwise = 0
        where
         facs = pfactor n prime
         len = genericLength facs 
 
divisor :: Integer -> Integer -> [Integer]
divisor n  p = sort $ map product $ sequence mul
  where
    fs = group $ pfactor n prime
    mul = map (scanl (*) 1) fs 
 

 
solve :: Integer  -> String
solve  n = show $ div ans n  where
        ans = sum .  map ( \t -> mobius ( div n t ) * 2 ^ t ) . sort . nub . divisor  n $ 1
 
main = interact $ unlines . map ( solve . read ) . lines