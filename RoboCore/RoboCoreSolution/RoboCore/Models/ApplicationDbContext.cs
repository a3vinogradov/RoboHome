using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using System.Reflection.Emit;

namespace RoboCore.Models
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }
        public DbSet<RoboDeviceEntity> RoboDeviceEntities { get; set; }
        public DbSet<RoboDeviceTypeEntity> RoboDeviceTypeEntities { get; set; }
        public DbSet<RoboDeviceHistoryEntity> RoboDeviceHistoryEntities { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // Дополнительная конфигурация модели
        }
    }
}
