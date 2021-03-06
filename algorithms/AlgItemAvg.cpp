#include "AlgItemAvg.h"

using namespace std;


AlgItemAvg::AlgItemAvg( DataReader& dreader,
                        int userpos,
                        int itempos,
                        int ratingpos )
: RecSysAlgorithm< boost::numeric::ublas::mapped_matrix<double, boost::numeric::ublas::column_major> >( dreader, userpos, itempos, ratingpos )
{
}

int AlgItemAvg::train()
{
   for( size_t i = 0 ; i < m_ratingMatrix.items() ; ++i )
   {
      string itemId = m_ratingMatrix.itemId( i );
      double sumbycol = 0;
      int countbycol = m_ratingMatrix.sumColumn( i, sumbycol );
      if( 0 < countbycol )
      {
         m_meanRatingByItem[itemId] = sumbycol/countbycol;
      }

      if( !m_running )
      {
         return STOPPED;
      }
   }

   return FINISHED;
}

double AlgItemAvg::predict( string& userId, string& itemId )
{
   double p = -1;
   if( m_meanRatingByItem.find( itemId ) != m_meanRatingByItem.end() )
   {
      p = m_meanRatingByItem[itemId];
   }
   return p > 0 ? p : m_globalMean;
}

double AlgItemAvg::predict( size_t userrow, size_t itemcol )
{
   double p = -1;
   string itemId = m_ratingMatrix.itemId( itemcol );
   if( !itemId.empty() )
   {
      p = m_meanRatingByItem[itemId];
   }
   return p > 0 ? p : m_globalMean;
}


