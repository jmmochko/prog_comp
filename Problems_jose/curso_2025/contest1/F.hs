import Control.Monad (replicateM_, replicateM)
import Data.Array (Array, listArray, (!))

type Pair = (Int, Int)

solve :: Array Int Pair -> Array Int Int -> Int -> Int -> Int
solve copias largo i k
    | i == 0    = k
    | k < prevLargo = solve copias largo (i - 1) k
    | otherwise = solve copias largo (i - 1) (posInCopy + l)
  where
    prevLargo = largo ! (i - 1)
    posInCopy = k - prevLargo
    (l, _) = copias ! i

main :: IO ()
main = do
    t <- readLn
    replicateM_ t $ do
        [n, c, q] <- map read . words <$> getLine
        s <- getLine
        copies <- map ((\[x, y] -> (x - 1, y - 1)) . map read . words) <$> replicateM c getLine
        let initialCopies = (0, n - 1) : copies
            copiasArr = listArray (0, c) initialCopies
            largoArr = listArray (0, c) $ scanl (+) n (map (\(l, r) -> r - l + 1) copies)
        queries <- map (subtract 1 . read) <$> replicateM q getLine
        let sArr = listArray (0, n - 1) s
        mapM_ (\k -> putChar (sArr ! solve copiasArr largoArr c k) >> putChar '\n') queries