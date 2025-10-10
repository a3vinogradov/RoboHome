using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace RoboCore.Migrations
{
    /// <inheritdoc />
    public partial class Init : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "RoboDeviceTypeEntities",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Description = table.Column<string>(type: "text", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_RoboDeviceTypeEntities", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "RoboDeviceEntities",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    DeviceTypeId = table.Column<int>(type: "integer", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Status = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_RoboDeviceEntities", x => x.Id);
                    table.ForeignKey(
                        name: "FK_RoboDeviceEntities_RoboDeviceTypeEntities_DeviceTypeId",
                        column: x => x.DeviceTypeId,
                        principalTable: "RoboDeviceTypeEntities",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "RoboDeviceHistoryEntities",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    RoboDeviceId = table.Column<int>(type: "integer", nullable: false),
                    Status = table.Column<int>(type: "integer", nullable: false),
                    UpdateDate = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    AdditionalInfo = table.Column<string>(type: "text", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_RoboDeviceHistoryEntities", x => x.Id);
                    table.ForeignKey(
                        name: "FK_RoboDeviceHistoryEntities_RoboDeviceEntities_RoboDeviceId",
                        column: x => x.RoboDeviceId,
                        principalTable: "RoboDeviceEntities",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_RoboDeviceEntities_DeviceTypeId",
                table: "RoboDeviceEntities",
                column: "DeviceTypeId");

            migrationBuilder.CreateIndex(
                name: "IX_RoboDeviceHistoryEntities_RoboDeviceId",
                table: "RoboDeviceHistoryEntities",
                column: "RoboDeviceId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "RoboDeviceHistoryEntities");

            migrationBuilder.DropTable(
                name: "RoboDeviceEntities");

            migrationBuilder.DropTable(
                name: "RoboDeviceTypeEntities");
        }
    }
}
